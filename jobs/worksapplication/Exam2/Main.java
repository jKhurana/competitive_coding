/**
 * 
 */
import java.util.*;

/**
 * @author jatinkhurana
 *
 */
public class Main {

	// Adjacancy matrix representation of tree
	private static HashMap<Integer,ArrayList<Integer>> tree=new HashMap<Integer,ArrayList<Integer>>();
	// n- Number of Node of tree, m- Number of Query
	static int n,m;
	// ith element of distance matrix represents distance of node i from nearest Festival Node
	static int distance[];	
	

	/* Utility Method to initialize array to default value*/
	private static void initializeArray(int arr[],int value)
	{
		for(int i=0;i<arr.length;i++)
			arr[i]=value;
	}

	
	// method to read the input and process the user quieries
	private static void processQuery()
	{
		Scanner sc=new Scanner(System.in);
		// read the value of n and m
		String line[] = sc.nextLine().split(" ");
		n=Integer.parseInt(line[0]);
		m=Integer.parseInt(line[1]);
		distance=new int[n+1];

		// read tree n-1 edges
		for(int i=1;i<n;i++)
		{
			line=sc.nextLine().split(" ");
			int v1=Integer.parseInt(line[0]);
			int v2=Integer.parseInt(line[1]);

			// add v1 to the adjacency list of v2 
			if(tree.containsKey(v1))
			{
				tree.get(v1).add(v2);
			}
			else
			{
				ArrayList<Integer> adjlist=new ArrayList<Integer>();
				adjlist.add(v2);
				tree.put(v1, adjlist);
			}

			// add v2 to the adjacency list of v1
			if(tree.containsKey(v2))
			{
				tree.get(v2).add(v1);
			}
			else
			{
				ArrayList<Integer> adjlist=new ArrayList<Integer>();
				adjlist.add(v1);
				tree.put(v2, adjlist);
			}
		}

		// Now tree is constructed , initialize the initial distance of City from nearest festival City 
		initialDistance();

		/* Now read each Query
		QueryType = 1 ===>  Update the distance of Ciiies 
		QUERYType = 2 ===>  Find the nearest distance  */
		for(int i=0;i<m;i++)
		{
			line = sc.nextLine().split(" ");
			int queryType=Integer.parseInt(line[0]);
			int vertex=Integer.parseInt(line[1]);
			if(queryType==1)
				updateDistance(vertex);
			else
				System.out.println(findDistance(vertex));
		}
		sc.close();
		
	}
	
	/* This method initialize the distance of each city initially
	A marker -1 is used in the queue to diffrentiate the tree levels.*/
	private static void initialDistance()
	{
		int visited[]=new int[n+1];
		initializeArray(visited, 0);
		Queue<Integer> que=new LinkedList<Integer>();
		que.add(1);
		visited[1]=1;
		que.add(-1); // add level flag
		int dist=0;
		while(true)
		{
			int vertex=que.remove();
			if(vertex==-1)
			{
				dist++;
				if(que.isEmpty())
					break;
				else
					que.add(-1);
			}
			else
			{
				distance[vertex]=dist;
				for(Integer adj:tree.get(vertex))
				{
					if(visited[adj]==0)
					{
						que.add(adj);
						visited[adj]=1;
					}
				}
			}
		}
	}
	
	/* This method update the distance of each node to the nearest node once some other Node is assigned as Festival Node
	This method take O(n) time where n is the number of nodes in the tree

	A marker -1 in the queue to identify the change of level in the tree */
	private static void updateDistance(int vertex)
	{
		
		// If Given city already has festival then return
		if(distance[vertex]==0)
			return;

		int dist=0;
		int visited[]=new int[n+1];
		initializeArray(visited, 0);
		
		Queue<Integer> que=new LinkedList<Integer>();
		que.add(vertex);
		visited[vertex]=1;
		que.add(-1); // level change mark
		
		while(true)
		{
			int v=que.remove();
			// Marker founds means level change
			if(v==-1)
			{
				dist++;
				if(que.isEmpty())
					break;
				else
					que.add(-1);
			}
			else
			{
				if(distance[v]>dist)
				{
					distance[v]=dist;
					for(Integer adj:tree.get(v))
					{
						if(visited[adj]==0)
						{
							que.add(adj);
							visited[adj]=1;
						}
					}
				}
			}
		}
	}

/* This method find the distance of City city from the nearest festival city. 
This method take O(1) time to find the distance from the nearest festival city.*/
private static int findDistance(int city)
{
	return distance[city];
	}


// Main method
public static void main(String[] args) {
		
		processQuery();
	}

}
